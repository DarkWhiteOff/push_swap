package book_keeper

import (
	"errors"
)

const DeathNoticeLatency = 10 // in milliseconds

type BookKeeper struct {
	Forks              []ForkStatus
	Philos             []PhiloStatus
	DeathNoticeLatency int
	T2Live             int
	T2Eat              int
	T2Sleep            int
	NPhilos            int
	NMeals             int
	DeathHappened      bool
}

func NewBookKeeper(NPhilos, T2Live, T2Eat, T2Sleep, NMeals int) *BookKeeper {
	keeper := &BookKeeper{
		Forks:              make([]ForkStatus, NPhilos+1),
		Philos:             make([]PhiloStatus, NPhilos+1),
		DeathNoticeLatency: DeathNoticeLatency,
		T2Live:             T2Live,
		T2Eat:              T2Eat,
		T2Sleep:            T2Sleep,
		NPhilos:            NPhilos,
		NMeals:             NMeals,
	}
	keeper.Forks[0] = Taken
	for i := range keeper.Philos {
		keeper.Philos[i].NMeals = NMeals
	}
	return keeper
}

func getForkId(philoId, nForks int) (int, int) {
	var leftForkId, rightForkId int

	leftForkId, rightForkId = philoId, philoId+1
	if rightForkId > nForks {
		rightForkId = 1
	}
	return leftForkId, rightForkId
}

func grabFork(philoId int, forks []ForkStatus) error {
	leftForkId, rightForkId := getForkId(philoId, len(forks)-1)
	if forks[leftForkId] == Available {
		forks[leftForkId] = Taken
	} else if forks[rightForkId] == Available {
		forks[rightForkId] = Taken
	} else {
		return errors.New("philo should not duplicate forks")
	}
	return nil
}

func releaseFork(philoId int, forks []ForkStatus) {
	leftForkId, rightForkId := getForkId(philoId, len(forks)-1)
	forks[leftForkId] = Available
	forks[rightForkId] = Available
}

func validateEvent(b *BookKeeper, philoId int, e PhiloEvent) error {
	if (philoId < 1) || (philoId > b.NPhilos) {
		return errors.New("invalid philosopher ID")
	}
	if e.Type != Dead && e.Timestamp > int64(b.T2Live)+b.Philos[philoId].LastMeal {
		return errors.New("philosopher is still active after death")
	}
	events := &b.Philos[philoId].Events
	nEvents := len(*events)
	if nEvents > 0 && e.Timestamp < (*events)[nEvents-1].Timestamp {
		return errors.New("event timestamp is incorrect")
	}
	switch e.Type {
	case Eating:
		if nEvents < 2 || (*events)[nEvents-1].Type != HoldingFork ||
			(*events)[nEvents-2].Type != HoldingFork {
			return errors.New("philosopher does not hold two forks before eating")
		}
	case HoldingFork:
		holdingForkEvents := 0
		for i := nEvents - 1; i >= 0 && (*events)[i].Type != Eating; i-- {
			if (*events)[i].Type == HoldingFork {
				holdingForkEvents++
			}
		}
		if holdingForkEvents > 1 {
			return errors.New("philosopher is holding more than two forks")
		}
		if nEvents >= 1 && (*events)[nEvents-1].Type != HoldingFork && holdingForkEvents > 0 {
			return errors.New("philosopher is doing something else while picking up forks to eat")
		}
		if err := grabFork(philoId, b.Forks); err != nil {
			return err
		}
	case Sleeping:
		releaseFork(philoId, b.Forks)
		if nEvents < 1 || (*events)[nEvents-1].Type != Eating {
			return errors.New("philosopher does not eat before sleeping")
		}
	case Dead:
		if e.Timestamp > int64(b.T2Live)+b.Philos[philoId].LastMeal+int64(b.DeathNoticeLatency) {
			return errors.New("philosopher 's death notice is too late")
		}
	default:
	}
	return nil
}

func (b *BookKeeper) Add(philoId int, e PhiloEvent) error {
	if err := validateEvent(b, philoId, e); err != nil {
		return err
	}
	b.Philos[philoId].Events = append(b.Philos[philoId].Events, e)
	if e.Type == Eating {
		b.Philos[philoId].LastMeal = e.Timestamp
		b.Philos[philoId].NMeals--
	}
	return nil
}

func (b *BookKeeper) Finalize() error {
	var deathTime int64
	for i := 1; i <= b.NPhilos; i++ {
		p := b.Philos[i]
		for i := len(p.Events) - 1; i >= 0; i-- {
			if p.Events[i].Type == Dead {
				if i != len(p.Events)-1 {
					return errors.New("philosopher is still active after death")
				}
				if deathTime == 0 {
					deathTime = p.Events[i].Timestamp
				} else if p.Events[i].Timestamp != deathTime {
					return errors.New("simulation does not stop right after a philosopher dies")
				}
			}
		}
	}
	b.DeathHappened = deathTime != 0
	if !b.DeathHappened {
		for i := 1; i <= b.NPhilos; i++ {
			if b.Philos[i].NMeals > 0 {
				return errors.New("philosopher has not eaten enough meals")
			}
		}
	}
	return nil
}
